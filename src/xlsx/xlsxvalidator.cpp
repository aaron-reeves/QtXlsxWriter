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

#include "xlsxvalidator.h"
#include "xlsxcellrange.h"
#include "xlsxcellreference.h"

QT_BEGIN_NAMESPACE_XLSX

void Validator::validateAny()
{
    m_type = VT_Any;
    m_comparator = Comparator();
}

void Validator::validateInteger(const Comparator &comparator)
{
    m_type = VT_Integer;
    m_comparator = comparator;
}

void Validator::validateDecimal(const Comparator &comparator)
{
    m_type = VT_Decimal;
    m_comparator = comparator;
}

void Validator::validateDate(const Comparator &comparator)
{
    m_type = VT_Date;
    m_comparator = comparator;
}

void Validator::validateTime(const Comparator &comparator)
{
    m_type = VT_Time;
    m_comparator = comparator;
}

QT_END_NAMESPACE_XLSX
