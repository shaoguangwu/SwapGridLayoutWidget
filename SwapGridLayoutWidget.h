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

#ifndef SWAPGRIDLAYOUTWIDGET_H
#define SWAPGRIDLAYOUTWIDGET_H

class QGridLayout;
class QWidget;

/**
 * Swap QWidget w1 and w2 in layout.
 * Make sure that the layout contains w1 and w2.
*/
void swapGridLayoutWidget(QGridLayout* layout, QWidget* w1, QWidget* w2);

/**
 * Safe version.
 * If layout contains w1 and w2, swap them and return true. Otherwise do nothing and return false.
*/
bool swapGridLayoutWidget_s(QGridLayout* layout, QWidget* w1, QWidget* w2);

#endif // SWAPGRIDLAYOUTWIDGET_H
