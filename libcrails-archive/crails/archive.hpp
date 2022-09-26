#ifndef  CRAILS_ARCHIVE_HPP
# define CRAILS_ARCHIVE_HPP

# include <libtext-archive/archive.hpp>
# include <crails/datatree.hpp>

template<> char Archive::typecode<DataTree>();
template<> void OArchive::serialize<DataTree>(const DataTree& value);
template<> void IArchive::unserialize<DataTree>(DataTree& value);

#endif
