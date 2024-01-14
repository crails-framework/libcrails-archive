#ifndef  CRAILS_ARCHIVE_RENDERER_HPP
# define CRAILS_ARCHIVE_RENDERER_HPP

# include <crails/renderer.hpp>

namespace Crails
{
  class ArchiveRenderer : public Renderer
  {
  public:
    ArchiveRenderer();

    const std::vector<std::string>& get_mimetypes() const override;
    bool can_render(const std::string& view) const override;
    void render_template(const std::string& view, RenderTarget& response, SharedVars& vars) const override;
  };
}

#endif
