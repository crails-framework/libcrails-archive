#include <libtext-archive/archive.hpp>
#include "archive_renderer.hpp"

using namespace Crails;

bool ArchiveRenderer::can_render(const std::string& accept_header, const std::string& view) const
{
  if (accept_header.find(Archive::mimetype) != std::string::npos)
    return templates.find(view) != templates.end();
  return false;
}

void ArchiveRenderer::render_template(const std::string& view, RenderTarget& response, SharedVars& vars) const
{
  auto tpl = templates.find(view);
  
  response.set_header("Content-Type", Archive::mimetype);
  (*tpl).second(*this, response, vars);
}
