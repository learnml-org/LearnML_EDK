#include <lml_edk/language.hpp>

namespace lml_edk
{
	paragraph::paragraph(const lml_pae::string& text)
		: text(text)
	{}
	paragraph::paragraph(const lml_pae::string& title, const lml_pae::string& text)
		: title(title), text(text)
	{}
	paragraph::paragraph(const paragraph& paragraph)
		: title(paragraph.title), text(paragraph.text)
	{}
	paragraph::paragraph(paragraph&& paragraph) noexcept
		: title(std::move(paragraph.title)), text(std::move(paragraph.text))
	{}

	paragraph& paragraph::operator=(const paragraph& paragraph)
	{
		title = paragraph.title;
		text = paragraph.text;
		return *this;
	}
	paragraph& paragraph::operator=(paragraph&& paragraph) noexcept
	{
		title = std::move(paragraph.title);
		text = std::move(paragraph.text);
		return *this;
	}
}