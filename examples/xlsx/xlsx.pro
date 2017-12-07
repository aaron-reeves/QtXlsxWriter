TEMPLATE = subdirs
SUBDIRS = hello \
    extractdata \
    style \
    documentproperty \
    image \
    mergecells \
    rowcolumn \
    numberformat \
    datavalidation \
    definename \
    formula \
    formulas \
    richtext \
    conditionalformatting \
    worksheetoperations \
    hyperlinks \
    marker \
    chart \
    chartsheet \
    calendar \
    demo

qtHaveModule(widgets): SUBDIRS += xlsxwidget

