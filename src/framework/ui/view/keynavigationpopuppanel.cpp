/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "keynavigationpopuppanel.h"

using namespace mu::ui;

KeyNavigationPopupPanel::KeyNavigationPopupPanel(QObject* parent)
    : KeyNavigationSubSection(parent)
{
}

KeyNavigationControl* KeyNavigationPopupPanel::parentControl() const
{
    return m_parentControl;
}

void KeyNavigationPopupPanel::setParentControl(KeyNavigationControl* parentControl)
{
    if (m_parentControl == parentControl) {
        return;
    }

    m_parentControl = parentControl;
    emit parentControlChanged(m_parentControl);

    if (m_parentControl && m_parentControl->subsection()) {
        setSection(m_parentControl->subsection()->section());
    } else {
        setSection(nullptr);
    }
}