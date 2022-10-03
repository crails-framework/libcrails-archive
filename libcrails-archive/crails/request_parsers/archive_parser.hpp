#ifndef  ARCHIVE_PARSER_HPP
# define ARCHIVE_PARSER_HPP

# include <crails/request_parser.hpp>

namespace Crails
{
  class RequestArchiveParser : public BodyParser
  {
  public:
    RequestArchiveParser(const char* parameter_key = "archive_data") : parameter_key(parameter_key) {}

    void operator()(Context&, std::function<void(RequestParser::Status)> callback) const;
  private:
    void body_received(Context&, const std::string& body) const;

    const char* parameter_key;
  };
}

#endif
