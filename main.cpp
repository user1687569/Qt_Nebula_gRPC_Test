#include <QCoreApplication>
#ifdef __cplusplus
extern "C"
{
#endif
#include "testing/testing.h"
#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("stdio.h\n");
    testing();

    return a.exec();
}
