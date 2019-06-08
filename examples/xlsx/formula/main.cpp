#include <QtCore>
#include "xlsxdocument.h"

QTXLSX_USE_NAMESPACE

int main()
{
    Document xlsx;
    for (int i=1; i<=10; ++i) {
        xlsx.write(i, 1, i);
        xlsx.write(i, 2, i*i);
        xlsx.write(i, 3, i*i*i);
    }
    Worksheet* sheet = xlsx.currentWorksheet();
    sheet->writeFormula(CellReference(11, 1),
                        CellFormula(Formula::AVERAGE(CellRange(1, 1, 10, 1)),
                                    CellReference::toString(11, 1),
                                    CellFormula::SharedType));
    sheet->writeFormula(CellReference(11, 2),
                        CellFormula(Formula::SUM(CellRange(1, 2, 10, 2)),
                                    CellReference::toString(11, 2),
                                    CellFormula::SharedType));
    sheet->writeFormula(CellReference(11, 3),
                        CellFormula(Formula::COUNTIF(CellRange(1, 3, 10, 3), QString("\">50\"")),
                                    CellReference::toString(11, 3),
                                    CellFormula::SharedType));
    xlsx.save();
    return 0;
}
