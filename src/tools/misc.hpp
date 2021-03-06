#ifndef GAPPA_TOOLS_MISC_H_
#define GAPPA_TOOLS_MISC_H_

/*
    gappa - Genesis Applications for Phylogenetic Placement Analysis
    Copyright (C) 2017-2019 Lucas Czech and HITS gGmbH

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Contact:
    Lucas Czech <lucas.czech@h-its.org>
    Exelixis Lab, Heidelberg Institute for Theoretical Studies
    Schloss-Wolfsbrunnenweg 35, D-69118 Heidelberg, Germany
*/

#include "CLI/CLI.hpp"

#include <iosfwd>
#include <string>
#include <stdexcept>

// =================================================================================================
//      Legacy Commands
// =================================================================================================

class RenamedCommandError : public std::runtime_error {

public:

    RenamedCommandError( std::string message )
        : std::runtime_error( message )
    {}
};

void add_legacy_command(
    CLI::App& app,
    std::string const& old_name,
    std::string const& new_path
);

// =================================================================================================
//      Formatting
// =================================================================================================

std::string format_columns(
    std::string const& left,
    std::string const& right,
    size_t left_w
);

void write_columns(
    std::ostream& out,
    std::string const& left,
    std::string const& right,
    size_t left_w,
    size_t right_w
);

// =================================================================================================
//      Misc
// =================================================================================================

std::string random_indexed_name( size_t index, size_t max );

#endif // include guard
