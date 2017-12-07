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

#ifndef QXLSX_FORMULA_H
#define QXLSX_FORMULA_H

#include <QString>

#include "xlsxglobal.h"

#include "xlsxcellrange.h"
#include "xlsxcellreference.h"

QT_BEGIN_NAMESPACE_XLSX

class Q_XLSX_EXPORT Formula
{
    template <class T>
    static QString listToString(const T& t)
    {
        return t.toString();
    }

    template <class T, class... Args>
    static QString listToString(const T& t, Args... args)
    {
        return t.toString() + ", " + listToString(args...);
    }

public:
    Formula();
    Formula(const Formula& formula);
    Formula(const CellRange& range);
    Formula(const CellReference& cell);
    ~Formula();

    QString toString() const;

    void clear();

    // template functions
    template <class T, class... Args>
    static Formula AVERAGE(const T& t, Args... args);
    template <class T, class... Args>
    static Formula COUNT(const T& t, Args... args);
    template <class T, class... Args>
    static Formula MAX(const T& t, Args... args);
    template <class T, class... Args>
    static Formula MIN(const T& t, Args... args);
    template <class T, class... Args>
    static Formula PRODUCT(const T& t, Args... args);
    template <class T, class... Args>
    static Formula SUM(const T& t, Args... args);
    template <class T, class... Args>
    static Formula SUMPRODUCT(const T& t, Args... args);

    static Formula AVEDEV(const CellRange& range);
    static Formula AVERAGEIF(const CellRange& range, const QString& criteria, const CellRange& average_range = CellRange());
    static Formula COUNTIF(const CellRange& range, const QString& criteria);
    static Formula COUNTIF(const CellRange& range, const CellReference& cell);
    static Formula IF(const QString& criteria, const QString& ifTrue, const QString& ifFalse);
    static Formula SUMIF(const CellRange& range, const QString& criteria, const CellRange& sum_range = CellRange());

    static Formula brace(const Formula& formula);

    Formula operator+ (const Formula& rhs) const;
    Formula operator- (const Formula& rhs) const;
    Formula operator* (const Formula& rhs) const;
    Formula operator/ (const Formula& rhs) const;

    Formula& operator+=(const Formula& rhs);
    Formula& operator-=(const Formula& rhs);
    Formula& operator*=(const Formula& rhs);
    Formula& operator/=(const Formula& rhs);

    bool operator== (const Formula& rhs) const;
    bool operator!= (const Formula& rhs) const;
    Formula& operator=(const Formula& rhs);

private:
    Formula(const QString& string);

    void append(const QString& string);

    QString m_formula;
};

template <class T, class... Args>
Formula Formula::AVERAGE(const T& t, Args... args)
{
    return Formula("AVERAGE(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::COUNT(const T& t, Args... args)
{
    return Formula("COUNT(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::MAX(const T& t, Args... args)
{
    return Formula("MAX(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::MIN(const T& t, Args... args)
{
    return Formula("MIN(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::PRODUCT(const T& t, Args... args)
{
    return Formula("PRODUCT(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::SUM(const T& t, Args... args)
{
    return Formula("SUM(" + listToString(t, args...) + ")");
}

template <class T, class... Args>
Formula Formula::SUMPRODUCT(const T& t, Args... args)
{
    return Formula("SUMPRODUCT(" + listToString(t, args...) + ")");
}

QT_END_NAMESPACE_XLSX

#endif // QXLSX_FORMULA_H
