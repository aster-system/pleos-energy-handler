//******************
//
// pleos_energy_handler.h
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
// This file contains tools for PLEOS physics softwares.
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

#ifndef PLEOS_PHYSIC
#define PLEOS_PHYSIC

#include "../../../scls-graphic-benoit/scls_graphic.h"

// Define some constants
// Values from https://physics.nist.gov/cuu/Constants/index.html
#ifndef PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT
#define PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT static_cast<long double>(1.66053906892e-27)
#endif // PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT
#ifndef PLEOS_PHYSIC_ELECTRON_MASS
#define PLEOS_PHYSIC_ELECTRON_MASS static_cast<long double>(9.1093837139e-31)
#endif // PLEOS_PHYSIC_ELECTRON_MASS
#ifndef PLEOS_PHYSIC_PROTON_MASS
#define PLEOS_PHYSIC_PROTON_MASS static_cast<long double>(1.67262192595e-27)
#endif // PLEOS_PHYSIC_PROTON_MASS
#ifndef PLEOS_PHYSIC_NEUTRON_MASS
#define PLEOS_PHYSIC_NEUTRON_MASS static_cast<long double>(1.67492750056e-27)
#endif // PLEOS_PHYSIC_NEUTRON_MASS

// The namespace "pleos::physic" is used to simplify the all.
namespace pleos { namespace physic {

    //******************
    //
    // The "Object", "Atoms" and "Molecules" class
    //
    //******************

    class Object {
        // Class representating a physic object
    public:
        // Object constructor
        Object() {};
    };

    class Atom_Datas : public Object {
        // Class representating an atom
    public:
        // Atom_Datas constructor
        Atom_Datas(std::string atom_name, std::string atom_symbol, unsigned char atomic_number, unsigned short neutrons_number) :
            Object(), a_atom_name(atom_name), a_atom_symbol(a_atom_symbol), a_atomic_number(atomic_number), a_neutrons_number(neutrons_number) {};

        // Getters and setters
        constexpr inline long double atomic_mass() const noexcept {return mass() / PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT;};
        constexpr inline unsigned int atomic_number() const noexcept {return static_cast<unsigned int>(a_atomic_number);};
        constexpr inline long double mass() const noexcept {return static_cast<long double>(a_atomic_number) * PLEOS_PHYSIC_ELECTRON_MASS + static_cast<long double>(a_atomic_number) * PLEOS_PHYSIC_PROTON_MASS + static_cast<long double>(a_neutrons_number) * PLEOS_PHYSIC_NEUTRON_MASS;};
        constexpr inline unsigned int neutron_number() const noexcept {return static_cast<unsigned int>(a_neutrons_number);};
        constexpr inline unsigned int proton_number() const noexcept {return static_cast<unsigned int>(a_atomic_number);};

    private:
        // Name of the atom
        const std::string a_atom_name;
        // Symbol of the atom
        const std::string a_atom_symbol;

        // Atomic number of the atom
        const unsigned char a_atomic_number;
        // Number of neutrons in the atom
        const unsigned short a_neutrons_number;
    };

    //******************
    //
    // The "Physic_Engine" class
    //
    //******************

    class Physic_Engine {
        // Class representating an engine to use physic
    public:
        // Physic_Engine constructor
        Physic_Engine() {load_atoms_datas();};

        // Load the needed atoms datas
        void load_atoms_datas();

        // Getters and setters
        inline std::vector<std::vector<std::shared_ptr<Atom_Datas>>>& atoms_datas() {return a_atoms_datas;};

    private:
        // Loaded atoms datas
        std::vector<std::vector<std::shared_ptr<Atom_Datas>>> a_atoms_datas;
    };
}}

#endif // PLEOS_PHYSIC
