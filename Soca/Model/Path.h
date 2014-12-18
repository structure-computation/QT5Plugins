/*
 Copyright 2012 Structure Computation  www.structure-computation.com
 Copyright 2012 Hugo Leclerc

 This file is part of Soca.

 Soca is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Soca is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with Soca. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef PATH_H
#define PATH_H

#include "ModelWithAttr.h"

/**
*/
class Path : public ModelWithAttr {
public:
    Path( QString _data = QString() );

    virtual void write_str( QDebug dbg ) const;
    virtual operator QString() const;
    virtual QString type() const;

    virtual bool _set( const char *str, int len );
    virtual void write_usr( BinOut &nut, BinOut &uut, Database *db );

    QString _data;
};

#endif // PATH_H
