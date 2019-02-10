#pragma once

#include <lml_edk/function.hpp>
#include <lml_edk/language.hpp>
#include <lml_le/log.hpp>
#include <lml_pae/string.hpp>

#include <cstdint>
#include <memory>

namespace lml
{
	class extension_engine;
}

namespace lml_edk
{
	class extension_base
	{
		friend class lml::extension_engine;

	public:
		extension_base(const extension_base&) = delete;
		virtual ~extension_base() = default;

	protected:
		extension_base() noexcept = default;

	public:
		extension_base& operator=(const extension_base&) = delete;

	public:
		virtual lml_pae::string name() const = 0;
		virtual lml_pae::string developer() const = 0;
		virtual lml_pae::string display_version() const = 0;
		virtual std::uint64_t version() const noexcept = 0;
		virtual const function_table& functions() const = 0;

	protected:
		lml_le::logger& logger() noexcept;

	private:
		lml_le::logger* logger_;
	};

	using extension_base_ptr = std::shared_ptr<extension_base>;

	inline namespace v1_0_0
	{
		class extension : public extension_base
		{
		public:
			extension(const extension&) = delete;
			virtual ~extension() override = default;

		protected:
			extension() noexcept = default;

		public:
			extension& operator=(const extension&) = delete;

		public:
			virtual const function_table& functions() const override final;

			// Parameter:
			// - version: std::uint64_t
			// Result: bool
			virtual function_result enabled(function_parameter arg) = 0;
			// Parameter: Nothing
			// Result: no_return_t
			virtual function_result disabled(function_parameter arg) = 0;
			// Parameter:
			// - language: language
			// Result: language
			virtual function_result change_language(function_parameter arg) = 0;

			// Parameter: Nothing
			// Result: std::vector<layer_allocator_ptr>
			virtual function_result layers(function_parameter arg) = 0;
		};
	}
}