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

        // Helium atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Hélium"), "He", 2, 2);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Lithium atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Lithium"), "Li", 3, 3);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Lithium"), "Li", 3, 4);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Beryllium atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Béryllium"), "Be", 4, 5);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Bore atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Bore"), "B", 5, 5);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Bore"), "B", 5, 6);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Carbon atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Carbone"), "C", 6, 6);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Carbone"), "C", 6, 7);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Nitrogen atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Azote"), "N", 7, 7);
        current_atom.push_back(current_isotope);
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Azote"), "N", 7, 8);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Oxygen atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Oxygène"), "O", 8, 8);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Sulfur atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Soufre"), "S", 16, 16);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Iron atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Fer"), "Fe", 26, 30);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();

        // Oganesson atom
        current_isotope = std::make_shared<Atom_Datas>(scls::to_utf_8_code_point("Oganesson"), "Og", 118, 176);
        current_atom.push_back(current_isotope);
        a_atoms_datas.push_back(current_atom);
        current_atom.clear();
    }

    // Load the needed molecules datas
    void Physic_Engine::load_molecules_datas() {
        a_molecules_datas.clear();
        std::shared_ptr<Molecule_Datas> current_molecule;

        // CO2 atom
        current_molecule = std::make_shared<Molecule_Datas>(scls::to_utf_8_code_point("Dioxyde de carbon"));
        current_molecule.get()->add_atom(a_atoms_datas[7][0], 2);
        current_molecule.get()->add_atom(a_atoms_datas[5][1], 1);
        a_molecules_datas.push_back(current_molecule);

        // C4H10 atom
        current_molecule = std::make_shared<Molecule_Datas>(scls::to_utf_8_code_point("Butane"));
        current_molecule.get()->add_atom(a_atoms_datas[0][0], 10);
        current_molecule.get()->add_atom(a_atoms_datas[5][1], 4);
        std::cout << current_molecule.get()->mass() << " " << current_molecule.get()->mole_by_mass() << std::endl;
        a_molecules_datas.push_back(current_molecule);

        // C12H26 atom
        current_molecule = std::make_shared<Molecule_Datas>(scls::to_utf_8_code_point("Dodécane"));
        current_molecule.get()->add_atom(a_atoms_datas[0][0], 26);
        current_molecule.get()->add_atom(a_atoms_datas[5][1], 12);
        a_molecules_datas.push_back(current_molecule);
    }
}}
