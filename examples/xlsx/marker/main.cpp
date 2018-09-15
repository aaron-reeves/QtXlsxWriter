#include <QtCore>
#include "xlsxdocument.h"
#include "xlsxchart.h"

QTXLSX_USE_NAMESPACE

int main()
{
    Document xlsx;
    for (int i=1; i<=10; ++i) {
        xlsx.write(i, 1, i);
        xlsx.write(i, 2, i*i);
        xlsx.write(i, 3, i*i*i);
    }
    Chart* chart = xlsx.insertChart(1, 4, QSize(400, 180));
    chart->setChartTytle(QStringLiteral("Test chart"));
    chart->setChartType(Chart::CT_Line);
    chart->enableAxisMajorGridLines(Chart::AT_Y, true);
    chart->setAxisMinScope(Chart::AT_Y, 0.0);
    chart->addSeries(QString("B1:B10"), 0, ChartLine(Marker(Marker::MT_X), QString(), false));
    chart->addSeries(QString("C1:C10"), 0, ChartLine(Marker(Marker::MT_Dot), QString(), false));

    xlsx.save();
    return 0;
}
