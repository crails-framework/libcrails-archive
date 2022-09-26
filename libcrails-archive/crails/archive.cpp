#include "archive.hpp"

template<> char Archive::typecode<DataTree>() { return 'r'; }

template<> void OArchive::serialize<DataTree>(const DataTree& value)
{
  serialize(value.as_data().to_json());
}

template<> void IArchive::unserialize<DataTree>(DataTree& value)
{
  std::string json;

  unserialize(json);
  value.from_json(json);
}
