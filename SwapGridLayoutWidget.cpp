/****************************************************************************
**
** Copyright (C) 2021 Wu Shaoguang.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License. See accompanying LICENSE file.
**
****************************************************************************/

#include "SwapGridLayoutWidget.h"

#include <QGridLayout>
#include <QWidget>

void swapGridLayoutWidget(QGridLayout* layout, QWidget* w1, QWidget* w2)
{
    int row1, col1, rowSpan1, colSpan1;
    int row2, col2, rowSpan2, colSpan2;

    int index1 = layout->indexOf(w1);
    layout->getItemPosition(index1, &row1, &col1, &rowSpan1, &colSpan1);
    auto layoutItem1 = layout->takeAt(index1);

    int index2 = layout->indexOf(w2);
    layout->getItemPosition(index2, &row2, &col2, &rowSpan2, &colSpan2);
    auto layoutItem2 = layout->takeAt(index2);

    layout->addItem(layoutItem1, row2, col2, rowSpan2, colSpan2);
    layout->addItem(layoutItem2, row1, col1, rowSpan1, colSpan1);
}

bool swapGridLayoutWidget_s(QGridLayout* layout, QWidget* w1, QWidget* w2)
{
    int row1, col1, rowSpan1, colSpan1;
    int row2, col2, rowSpan2, colSpan2;

    int index1 = layout->indexOf(w1);
    if (-1 == index1) {
        return false;
    }
    layout->getItemPosition(index1, &row1, &col1, &rowSpan1, &colSpan1);
    auto layoutItem1 = layout->takeAt(index1);

    int index2 = layout->indexOf(w2);
    if (-1 == index2) {
        // restore and return.
        layout->addItem(layoutItem1, row1, col1, rowSpan1, colSpan1);
        return false;
    }
    layout->getItemPosition(index2, &row2, &col2, &rowSpan2, &colSpan2);
    auto layoutItem2 = layout->takeAt(index2);

    layout->addItem(layoutItem1, row2, col2, rowSpan2, colSpan2);
    layout->addItem(layoutItem2, row1, col1, rowSpan1, colSpan1);
    return true;
}
