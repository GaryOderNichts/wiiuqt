#include "../WiiUQt/includes.h"
#include "../WiiUQt/nandbin.h"
#include "../WiiUQt/tools.h"

void Usage()
{
    qWarning() << "usage:" << QCoreApplication::arguments().at(0) << "<input nand> <src file> <dst path>";
    exit(1);
}

void Fail(const QString& str)
{
    qCritical() << str;
    exit(1);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList args = QCoreApplication::arguments();

    if(args.size() < 4) {
        Usage();
    }

    if(!QFile(args.at(1)).exists()) {
        Usage();
    }

    if(!QFile(args.at(2)).exists()) {
        Usage();
    }

    NandBin nand;
    if(!nand.SetPath(args.at(1)) || !nand.InitNand()) {
        Fail("Error setting path to nand object");
    }
    
    if (nand.DumpType() != NAND_DUMP_ECC) {
        Fail("ERROR: Must be full NAND dump! (with ecc and spare data)");
    }
    if (nand.NandType() != NAND_WIIU) {
        Fail("ERROR: Not WiiU SLC NAND");
    }

    QFile srcFile(args.at(2));
    if(!srcFile.open(QIODevice::ReadOnly)) {
        Usage();
    }

    QByteArray data = srcFile.readAll();

    qDebug() << "Writing file";
    if (!nand.SetData(args.at(3), data)) {
        Fail("Failed to write file");
    }

    if (!nand.WriteMetaData()) {
        Fail ("Failed to write metadata, dump may be corrupted now");
    }

    qInfo("Done!");

    return 0;
}
