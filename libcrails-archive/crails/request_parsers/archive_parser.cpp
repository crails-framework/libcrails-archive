#include <libtext-archive/archive.hpp>
#include <crails/context.hpp>
#include "archive_parser.hpp"

using namespace std;
using namespace Crails;

void RequestArchiveParser::operator()(Context& context, function<void(RequestParser::Status)> callback) const
{
  static const regex is_form(Archive::mimetype, regex_constants::extended);
  const HttpRequest& request = context.connection->get_request();

  if (request.method() != HttpVerb::get && content_type_matches(request, is_form))
  {
    wait_for_body(context, [callback]()
    {
      callback(RequestParser::Stop);
    });
  }
  else
    callback(RequestParser::Continue);
}

void RequestArchiveParser::body_received(Context& context, const string& body) const
{
  if (body.size() > 0)
    context.params["_archive_data"] = body;
}

