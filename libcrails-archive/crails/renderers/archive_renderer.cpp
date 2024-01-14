#include <libtext-archive/archive.hpp>
#include "archive_renderer.hpp"

using namespace Crails;
using namespace std;

static const vector<string> mimetypes{Archive::mimetype};

const vector<string>& ArchiveRenderer::get_mimetypes() const
{
  return mimetypes;
}

bool ArchiveRenderer::can_render(const std::string& view) const
{
  return templates.find(view) != templates.end();
}

void ArchiveRenderer::render_template(const std::string& view, RenderTarget& response, SharedVars& vars) const
{
  auto tpl = templates.find(view);
  
  response.set_header("Content-Type", Archive::mimetype);
  (*tpl).second(*this, response, vars);
}
