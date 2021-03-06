#ifndef GAPPA_COMMANDS_ANALYZE_H_
#define GAPPA_COMMANDS_ANALYZE_H_

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

#include "commands/analyze/correlation.hpp"
#include "commands/analyze/dispersion.hpp"
#include "commands/analyze/edgepca.hpp"
#include "commands/analyze/kmeans_imbalance.hpp"
#include "commands/analyze/kmeans_phylogenetic.hpp"
#include "commands/analyze/krd.hpp"
#include "commands/analyze/nhd.hpp"
#include "commands/analyze/placement_factorization.hpp"
#include "commands/analyze/squash.hpp"

#include "options/global.hpp"
#include "tools/cli_setup.hpp"
#include "tools/misc.hpp"

#include <string>
#include <vector>

// =================================================================================================
//      Functions
// =================================================================================================

inline void setup_analyze( CLI::App& app )
{
    // Create the module subcommand objects.
    auto sub = app.add_subcommand(
        "analyze",
        "Commands for analyzing and comparing placement data, that is, finding differences and patterns."
    );
    sub->require_subcommand( 1 );

    // Add module subcommands.
    setup_correlation( *sub );
    setup_dispersion( *sub );
    setup_edgepca( *sub );
    setup_ikmeans( *sub );
    setup_krd( *sub );
    setup_pkmeans( *sub );
    setup_placement_factorization( *sub );
    setup_squash( *sub );
    // setup_nhd( *sub );

    // Add the global options to each of the above subcommands.
    // This has to be run here, so that these options are added to all above commands,
    // but not to the legacy commands that come next.
    global_options.add_to_module( *sub );
    set_module_help_group( *sub );

    // Add legacy commands.
    add_legacy_command( *sub, "assign", "examine assign" );
    add_legacy_command( *sub, "edpl", "examine edpl" );
    add_legacy_command( *sub, "graft", "examine graft" );
    add_legacy_command( *sub, "lwr", "examine lwr" );
    add_legacy_command( *sub, "visualize-color", "examine heat-tree" );
}

#endif // include guard
