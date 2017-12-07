/****************************************************************************
** Copyright (c) 2016 Golubchikov Mihail <https://github.com/rue-ryuzaki>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following criterias:
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

#include "xlsxformula.h"

QT_BEGIN_NAMESPACE_XLSX

Formula::Formula()
    : m_formula()
{
}

Formula::Formula(const Formula& formula)
    : m_formula(formula.toString())
{
}

Formula::Formula(const CellRange& range)
    : m_formula(range.toString())
{
}

Formula::Formula(const CellReference& cell)
    : m_formula(cell.toString())
{
}

Formula::~Formula()
{
}

QString Formula::toString() const
{
    return m_formula;
}

void Formula::clear()
{
    m_formula.clear();
}

Formula Formula::AVEDEV(const CellRange& range)
{
    return Formula("AVEDEV(" + range.toString() + ")");
}

Formula Formula::AVERAGEIF(const CellRange& range, const QString& criteria, const CellRange& average_range)
{
    return Formula("AVERAGEIF(" + range.toString() + ", " + criteria + (average_range.isValid() ? (", " + average_range.toString()) : QString()) + ")");
}

Formula Formula::COUNTIF(const CellRange& range, const QString& criteria)
{
    return Formula("COUNTIF(" + range.toString() + ", " + criteria + ")");
}

Formula Formula::COUNTIF(const CellRange& range, const CellReference& cell)
{
    return Formula("COUNTIF(" + range.toString() + ", " + cell.toString() + ")");
}

Formula Formula::IF(const QString& criteria, const QString& ifTrue, const QString& ifFalse)
{
    return Formula("IF(" + criteria + ", " + ifTrue + ", " + ifFalse + ")");
}

Formula Formula::SUMIF(const CellRange& range, const QString& criteria, const CellRange& sum_range)
{
    return Formula("SUMIF(" + range.toString() + ", " + criteria + (sum_range.isValid() ? (", " + sum_range.toString()) : QString()) + ")");
}

Formula Formula::brace(const Formula& f)
{
    Formula formula;
    formula.append(QLatin1String("("));
    formula.append(f.toString());
    formula.append(QLatin1String(")"));
    return formula;
}

Formula Formula::operator+ (const Formula& rhs) const
{
    Formula formula(*this);
    if (!rhs.toString().isEmpty()) {
        formula.append(QLatin1String(" + "));
        formula.append(rhs.toString());
    }
    return formula;
}

Formula Formula::operator- (const Formula& rhs) const
{
    Formula formula(*this);
    if (!rhs.toString().isEmpty()) {
        formula.append(QLatin1String(" - "));
        formula.append(rhs.toString());
    }
    return formula;
}

Formula Formula::operator* (const Formula& rhs) const
{
    Formula formula(*this);
    if (!rhs.toString().isEmpty()) {
        formula.append(QLatin1String(" * "));
        formula.append(rhs.toString());
    }
    return formula;
}

Formula Formula::operator/ (const Formula& rhs) const
{
    Formula formula(*this);
    if (!rhs.toString().isEmpty()) {
        formula.append(QLatin1String(" / "));
        formula.append(rhs.toString());
    }
    return formula;
}

Formula& Formula::operator+=(const Formula& rhs)
{
    if (this != &rhs) {
        *this = *this + rhs;
    } else {
        if (!rhs.toString().isEmpty()) {
            QString temp = this->toString(); 
            this->append(QLatin1String(" + "));
            this->append(temp);
        }
    }
    return *this;
}

Formula& Formula::operator-=(const Formula& rhs)
{
    if (this != &rhs) {
        *this = *this - rhs;
    } else {
        if (!rhs.toString().isEmpty()) {
            QString temp = this->toString(); 
            this->append(QLatin1String(" - "));
            this->append(temp);
        }
    }
    return *this;
}

Formula& Formula::operator*=(const Formula& rhs)
{
    if (this != &rhs) {
        *this = *this * rhs;
    } else {
        if (!rhs.toString().isEmpty()) {
            QString temp = this->toString(); 
            this->append(QLatin1String(" * "));
            this->append(temp);
        }
    }
    return *this;
}

Formula& Formula::operator/=(const Formula& rhs)
{
    if (this != &rhs) {
        *this = *this / rhs;
    } else {
        if (!rhs.toString().isEmpty()) {
            QString temp = this->toString(); 
            this->append(QLatin1String(" / "));
            this->append(temp);
        }
    }
    return *this;
}

bool Formula::operator== (const Formula& rhs) const
{
    return (rhs.toString() == this->toString());
}

bool Formula::operator!= (const Formula& rhs) const
{
    return !(*this == rhs);
}

Formula& Formula::operator=(const Formula& rhs)
{
    if (this != &rhs) {
        this->m_formula = rhs.toString();
    }
    return *this;
}

Formula::Formula(const QString& string)
    : m_formula(string)
{
}

void Formula::append(const QString& string)
{
    m_formula += string;
}

QT_END_NAMESPACE_XLSX
