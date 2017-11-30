/****************************************************************************
** Copyright (c) 2013-2014 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
#include "xlsxcellrange.h"
#include "xlsxcellreference.h"
#include <QString>
#include <QPoint>
#include <QStringList>

QT_BEGIN_NAMESPACE_XLSX

/*!
    \class CellRange
    \brief For a range "A1:B2" or single cell "A1"
    \inmodule QtXlsx

    The CellRange class stores the top left and bottom
    right rows and columns of a range in a worksheet.
*/

/*!
    Constructs an range, i.e. a range
    whose rowCount() and columnCount() are 0.
*/
CellRange::CellRange()
    : top(-1), left(-1), bottom(-2), right(-2), _sheet()
{
}

/*!
    Constructs the range from the given \a top, \a
    left, \a bottom and \a right rows and columns in sheet \a sheet.

    \sa topRow(), leftColumn(), bottomRow(), rightColumn(), sheet()
*/
CellRange::CellRange(int top, int left, int bottom, int right, const QString &sheet)
    : top(top), left(left), bottom(bottom), right(right), _sheet(sheet)
{
}

CellRange::CellRange(const CellReference &topLeft, const CellReference &bottomRight, const QString &sheet)
    : top(topLeft.row()), left(topLeft.column()), 
      bottom(bottomRight.row()), right(bottomRight.column()),
      _sheet(sheet)
{
    if (sheet.isEmpty()) {
        // get sheet name from cells
        if (topLeft.sheet() == bottomRight.sheet()) {
            _sheet = topLeft.sheet();
        } else {
            // TODO skip
        }
    }
}

/*!
    \overload
    Constructs the range form the given \a range string.
*/
CellRange::CellRange(const QString &range)
{
    init(range);
}

/*!
    \overload
    Constructs the range form the given \a range string.
*/
CellRange::CellRange(const char *range)
{
    init(QString::fromLatin1(range));
}

void CellRange::init(const QString &range)
{
    // TODO load sheet name
    QStringList rs = range.split(QLatin1Char(':'));
    if (rs.size() == 2) {
        CellReference start(rs[0]);
        CellReference end(rs[1]);
        top = start.row();
        left = start.column();
        bottom = end.row();
        right = end.column();
    } else {
        CellReference p(rs[0]);
        top = p.row();
        left = p.column();
        bottom = p.row();
        right = p.column();
    }
}

/*!
    Constructs a the range by copying the given \a
    other range.
*/
CellRange::CellRange(const CellRange &other)
    : top(other.top), left(other.left), bottom(other.bottom), right(other.right), _sheet(other._sheet)
{
}

/*!
    Destroys the range.
*/
CellRange::~CellRange()
{
}

/*!
     Convert the range to string notation, such as "A1:B5".
*/
QString CellRange::toString(bool row_abs, bool col_abs) const
{
    if (!isValid())
        return QString();

    if (left == right && top == bottom) {
        //Single cell
        return CellReference(top, left).toString(row_abs, col_abs);
    }

    QString sheet_name;
    if (!_sheet.isEmpty())
        sheet_name.append(QString("'%1'!").arg(_sheet)); // TODO [-Wdeprecated-declarations] : Use fromUtf8, QStringLiteral, or QLatin1String
    QString cell_1 = CellReference(top, left).toString(row_abs, col_abs);
    QString cell_2 = CellReference(bottom, right).toString(row_abs, col_abs);
    return sheet_name + cell_1 + QLatin1String(":") + cell_2;
}

/*!
     Convert the range to string notation, such as "A1:B5".
*/
QString CellRange::toString(int firstRow, int firstColumn, int lastRow, int lastColumn, const QString &sheet)
{
    CellRange cellRange(firstRow, firstColumn, lastRow, lastColumn, sheet);
    return cellRange.toString();
}

/*!
 * Returns true if the Range is valid.
 */
bool CellRange::isValid() const
{
    return left <= right && top <= bottom;
}

QT_END_NAMESPACE_XLSX
