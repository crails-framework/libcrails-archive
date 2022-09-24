#ifndef  ARCHIVE_PARSER_HPP
# define ARCHIVE_PARSER_HPP

# include <crails/request_parser.hpp>

namespace Crails
{
  class RequestArchiveParser : public BodyParser
  {
  public:
    void operator()(Context&, std::function<void(RequestParser::Status)> callback) const;
  private:
    void body_received(Context&, const std::string& body) const;
  };
}

#endif
