/****************************************************************************
** Copyright (c) 2017 Golubchikov Mihail <https://github.com/rue-ryuzaki>
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

#ifndef QXLSX_VALIDATOR_H
#define QXLSX_VALIDATOR_H

#include "xlsxglobal.h"

#include <QString>

QT_BEGIN_NAMESPACE_XLSX

class CellRange;

class Comparator
{
public:
    enum CompareType {
        CT_None,
        CT_Between,
        CT_Outside,
        CT_Equal,
        CT_NotEqual,
        CT_Greater,
        CT_Less,
        CT_GreaterEqual,
        CT_LessEqual
    };
    Comparator() { }

    inline CompareType type() const { return m_type; }

private:
    CompareType   m_type;
    CellRange     m_maximum; // or value, source, formula
    CellRange     m_minimum;
    bool          m_ignoreEmpty;
};

class Q_XLSX_EXPORT Validator
{
public:
    enum ValidatorType {
        VT_Any,
        VT_Integer,
        VT_Decimal,
        VT_List,
        VT_Date,
        VT_Time,
        VT_TextLength,
        VT_Custom
    };

    Validator() { }

    void validateAny();
    void validateInteger(const Comparator &comparator = Comparator());
    void validateDecimal(const Comparator &comparator = Comparator());
    void validateList(const QStringList& list);
    void validateList(const CellRange& range);
    void validateDate(const Comparator &comparator = Comparator());
    void validateTime(const Comparator &comparator = Comparator());
    void validateCustom(const CellRange& formula);

    inline ValidatorType validType() const { return m_type; }
    inline Comparator::CompareType compareType() const { return m_comparator.type(); }

private:
    ValidatorType m_type;
    Comparator    m_comparator;
};

QT_END_NAMESPACE_XLSX

#endif // QXLSX_VALIDATOR_H
