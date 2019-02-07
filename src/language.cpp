#include <lml_edk/language.hpp>

namespace lml_edk
{
	description::description(const lml_pae::string& text)
		: text(text)
	{}
	description::description(const lml_pae::string& title, const lml_pae::string& text)
		: title(title), text(text)
	{}
	description::description(const description& description)
		: title(description.title), text(description.text)
	{}
	description::description(description&& description) noexcept
		: title(std::move(description.title)), text(std::move(description.text))
	{}

	description& description::operator=(const description& description)
	{
		title = description.title;
		text = description.text;
		return *this;
	}
	description& description::operator=(description&& description) noexcept
	{
		title = std::move(description.title);
		text = std::move(description.text);
		return *this;
	}
}

namespace lml_edk
{
	std::optional<lml_pae::string> get_string(const global_string& string, language language) noexcept
	{
		if (auto iter = string.find(language); iter != string.end()) return iter->second;
		else return std::nullopt;
	}
	std::optional<description> get_string(const global_description& string, language language) noexcept
	{
		if (auto iter = string.find(language); iter != string.end()) return iter->second;
		else return std::nullopt;
	}
}