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
#define PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT 1.66053906892e-24
#endif // PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT
#ifndef PLEOS_PHYSIC_AVOGADRO_NUMBER
#define PLEOS_PHYSIC_AVOGADRO_NUMBER __Mass(6.02214076e23)
#endif // PLEOS_PHYSIC_AVOGADRO_NUMBER
#ifndef PLEOS_PHYSIC_ELECTRON_MASS
#define PLEOS_PHYSIC_ELECTRON_MASS __Mass(9.1093837139e-28)
#endif // PLEOS_PHYSIC_ELECTRON_MASS
#ifndef PLEOS_PHYSIC_PROTON_MASS
#define PLEOS_PHYSIC_PROTON_MASS __Mass(1.67262192595e-24)
#endif // PLEOS_PHYSIC_PROTON_MASS
#ifndef PLEOS_PHYSIC_NEUTRON_MASS
#define PLEOS_PHYSIC_NEUTRON_MASS __Mass(1.67492750056e-24)
#endif // PLEOS_PHYSIC_NEUTRON_MASS

// The namespace "pleos::physic" is used to simplify the all.
namespace pleos { namespace physic {

    //******************
    //
    // The "Object", "Atoms" and "Molecules" class
    //
    //******************

    class __Mass {
        // Class representating the mass of an object
    public:
        // __Mass constructor
        __Mass(long double value):a_mass(value){};
        __Mass():__Mass(0){};

        // Returns the value  in kg
        inline long double to_g() const {return a_mass;};

        // Operators
        // Operators with long double
        constexpr operator long double() const {return a_mass;};
        __Mass operator*(long double other_value) const {return __Mass(a_mass * other_value);};
        __Mass operator/(long double other_value) const {return __Mass(a_mass / other_value);};
        // Operators with __Mass
        __Mass operator+=(__Mass other_value) {a_mass += other_value.a_mass;};
        __Mass operator-=(__Mass other_value) {a_mass -= other_value.a_mass;};
        __Mass operator*=(__Mass other_value) {a_mass *= other_value.a_mass;};
        __Mass operator*(__Mass other_value) const {return __Mass(a_mass * other_value.a_mass);};
        __Mass operator/=(__Mass other_value) {a_mass /= other_value.a_mass;};
        __Mass operator/(__Mass other_value) const {return __Mass(a_mass / other_value.a_mass);};

    private:
        // Mass of the object in kg
        long double a_mass = 0;
    };

    class Object {
        // Class representating a physic object
    public:
        // Object constructor
        Object(std::string name): a_name(name) {};

        // handle the mass of the particule
        virtual __Mass mass() const {return __Mass(0);};
        inline long double mass_by_mole(long double tested_mole = 1) const {return tested_mole * (mass() * PLEOS_PHYSIC_AVOGADRO_NUMBER);};
        inline long double mole_by_mass(long double tested_mass = 1) const {return tested_mass / (mass() * PLEOS_PHYSIC_AVOGADRO_NUMBER);};

        // Getters and setters
        inline std::string name() const noexcept {return a_name;};

    private:
        // Name of the atom
        const std::string a_name;
    };

    class Atom_Datas : public Object {
        // Class representating an atom
    public:
        // Atom_Datas constructor
        Atom_Datas(std::string atom_name, std::string atom_symbol, unsigned char atomic_number, unsigned short neutrons_number) :
            Object(atom_name), a_atom_symbol(a_atom_symbol), a_atomic_number(atomic_number), a_neutrons_number(neutrons_number) {};

        // Getters and setters
        inline long double atomic_mass() const noexcept {return mass().to_g() / PLEOS_PHYSIC_ATOMIC_MASS_CONSTANT;};
        inline unsigned int atomic_number() const noexcept {return static_cast<unsigned int>(a_atomic_number);};
        // Does not count nuclear mass effect
        virtual __Mass mass() const override {return static_cast<long double>(a_atomic_number) * PLEOS_PHYSIC_PROTON_MASS + static_cast<long double>(a_neutrons_number) * PLEOS_PHYSIC_NEUTRON_MASS;};
        constexpr inline unsigned int neutron_number() const noexcept {return static_cast<unsigned int>(a_neutrons_number);};
        constexpr inline unsigned int proton_number() const noexcept {return static_cast<unsigned int>(a_atomic_number);};

    private:
        // Symbol of the atom
        const std::string a_atom_symbol;

        // Atomic number of the atom
        const unsigned char a_atomic_number;
        // Number of neutrons in the atom
        const unsigned short a_neutrons_number;
    };

    class Molecule_Datas : public Object {
        // Class representating a molecule
    public:
        // Atom_Datas constructor
        Molecule_Datas(std::string molecule_name) : Object(molecule_name) {};

        // Add an atome to the molecule
        inline void add_atom(std::shared_ptr<Atom_Datas> atom, unsigned short number = 1) {a_atoms.push_back(atom);a_atoms_number.push_back(number);};
        // Does not count nuclear mass effect
        virtual __Mass mass() const override {
            __Mass total_mass = 0;
            for(int i = 0;i<static_cast<int>(a_atoms.size());i++) {
                total_mass += a_atoms[i].get()->mass() * static_cast<long double>(a_atoms_number[i]);
            } return total_mass;
        };

        // Getters and setters
        inline std::vector<std::shared_ptr<Atom_Datas>>& atoms() {return a_atoms;};

    private:
        // Atoms in the molecule
        std::vector<std::shared_ptr<Atom_Datas>> a_atoms;
        std::vector<unsigned short> a_atoms_number;
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
        Physic_Engine() {load_atoms_datas();load_molecules_datas();};

        // Load the needed atoms datas
        void load_atoms_datas();
        // Load the needed molecules datas
        void load_molecules_datas();

        // Getters and setters
        inline std::vector<std::vector<std::shared_ptr<Atom_Datas>>>& atoms_datas() {return a_atoms_datas;};
        inline std::vector<std::shared_ptr<Molecule_Datas>>& molecules_datas() {return a_molecules_datas;};

    private:
        // Loaded atoms datas
        std::vector<std::vector<std::shared_ptr<Atom_Datas>>> a_atoms_datas;
        // Loaded mocules datas
        std::vector<std::shared_ptr<Molecule_Datas>> a_molecules_datas;
    };
}}

#endif // PLEOS_PHYSIC
