#pragma once

#include <lml_pae/string.hpp>

#include <map>
#include <optional>
#include <utility>

namespace lml_edk
{
	enum class language
	{
		ko, kor = ko,
		en, eng = en,
	};

	class description final
	{
	public:
		description(const lml_pae::string& text);
		description(const lml_pae::string& title, const lml_pae::string& text);
		description(const description& description);
		description(description&& description) noexcept;
		~description() = default;

	public:
		description& operator=(const description& description);
		description& operator=(description&& description) noexcept;

	public:
		lml_pae::string title;
		lml_pae::string text;
	};

	using global_string = std::map<language, lml_pae::string>;
	using global_description = std::map<language, description>;

	std::optional<lml_pae::string> get_string(const global_string& string, language language) noexcept;
	std::optional<description> get_string(const global_description& string, language language) noexcept;
}