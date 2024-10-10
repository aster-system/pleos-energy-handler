//******************
//
// main.cpp
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Energy handler" part aims physics lesson.
// Its goal is to explain how energy works, and its connections with others near concepts : forces, power...
//
// This file contains the main part of the software.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

#include "../headers/pleos_energy_handler.h"

SCLS_FOUNDATION_INIT
SCLS_MATH_INIT

int main() {
    pleos::physic::Physic_Engine engine;

    for(int i = 0;i<static_cast<int>(engine.atoms_datas().size());i++) {
        for(int j = 0;j<static_cast<int>(engine.atoms_datas()[i].size());j++) {
            scls::print("Information", engine.atoms_datas()[i][j].get()->name(), engine.atoms_datas()[i][j].get()->mass());
            scls::print("Information", engine.atoms_datas()[i][j].get()->name(), engine.atoms_datas()[i][j].get()->mass_by_mole(50));
            scls::print("Information", engine.atoms_datas()[i][j].get()->name(), engine.atoms_datas()[i][j].get()->mole_by_mass(50));
        }
    }
    return 0;
}
