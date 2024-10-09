//******************
//
// pleos_energy_handler.cpp
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
// This file contains the source code of "pleos_energy_handler.cpp".
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

#include "../headers/pleos_physic.h"

// The namespace "pleos::physic" is used to simplify the all.
namespace pleos { namespace physic {

    //******************
    //
    // The "Physic_Engine" class
    //
    //******************

    // Load the needed atoms datas
    void Physic_Engine::load_atoms_datas() {
        a_atoms_datas.clear();
        std::shared_ptr<Atom_Datas> current_isotope;
        std::vector<std::shared_ptr<Atom_Datas>> current_atom;

        // Hydrogen atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Hydrogène"), "H", 1, 0);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Deutérium"), "H", 1, 1);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Tritium"), "H", 1, 2);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();
    }
}}
