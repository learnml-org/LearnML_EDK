#pragma once

#include <lml_pae/string.hpp>

#include <vector>

namespace lml_edk
{
	enum class language
	{
		ko, kor = ko,
		en, eng = en,
	};

	class paragraph final
	{
	public:
		paragraph(const lml_pae::string& text);
		paragraph(const lml_pae::string& title, const lml_pae::string& text);
		paragraph(const paragraph& paragraph);
		paragraph(paragraph&& paragraph) noexcept;
		~paragraph() = default;

	public:
		paragraph& operator=(const paragraph& paragraph);
		paragraph& operator=(paragraph&& paragraph) noexcept;

	public:
		lml_pae::string title;
		lml_pae::string text;
	};

	using description = std::vector<paragraph>;
}