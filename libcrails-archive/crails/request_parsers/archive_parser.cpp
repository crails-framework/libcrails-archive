#include <libtext-archive/archive.hpp>
#include <crails/context.hpp>
#include <crails/environment.hpp>
#include <crails/logger.hpp>
#include "archive_parser.hpp"

using namespace std;
using namespace Crails;

static void display_debug_data(const string& body)
{
  IArchive archive;
  archive.set_data(body);
  logger << Logger::Debug << "Received archive:\n" << archive.description() << Logger::endl;
}

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
  {
    context.params[parameter_key] = body;
    if (Crails::environment != Crails::Production)
      display_debug_data(body);
  }
}
