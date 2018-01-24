/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2018 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "predicates.H"
#include "stringOps.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class StringType, class UnaryPredicate>
Foam::List<StringType> Foam::DirLister::list
(
    const UnaryPredicate& pred,
    const bool prune
) const
{
    // Initial list size and resizing increment
    static const int incr = 100;

    List<StringType> lst(incr);

    label nItems = 0;
    for (const auto& item: *this)
    {
        if (pred(item) ? !prune : prune)
        {
            if (nItems >= lst.size())
            {
                lst.setSize(lst.size() + incr);
            }

            lst[nItems++] = item;
        }
    }

    lst.setSize(nItems);

    return lst;
}


template<class StringType>
Foam::List<StringType> Foam::DirLister::list() const
{
    return list<StringType>(predicates::always());
}


template<class StringType, class UnaryPredicate>
Foam::List<StringType> Foam::DirLister::sorted
(
    const UnaryPredicate& pred,
    const bool prune
) const
{
    List<StringType> lst(list<StringType>(pred, prune));
    sort(lst, stringOps::natural_sort());

    return lst;
}


template<class StringType>
Foam::List<StringType> Foam::DirLister::sorted() const
{
    return sorted<StringType>(predicates::always());
}


// ************************************************************************* //