#pragma once
#include <inttypes.h>

namespace Blah
{
	struct Vec4;

	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		Color();
		Color(int rgb);
		Color(int rgb, float alpha);
		Color(uint8_t r, uint8_t g, uint8_t b);
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

		// Parses a Hex string in the format of "#00000000" or "0x00000000" or "00000000"
		Color(const char* hexCstr);

		// Premultiplies the Color
		void premultiply();

		// Sets a Hex string to the given buffer, in the format of RRGGBBAA
		// The buffer must be at least 8 bytes long
		void to_hex_rgba(char* buffer) const;

		// Sets a Hex string to the given buffer, in the format of RRGGBB
		// The buffer must be at least 6 bytes long
		void to_hex_rgb(char* buffer) const;

		uint32_t to_rgba() const;

		Vec4 to_vec4() const;

		// Returns a RGBA Color representation of the integer value
		static Color from_rgba(uint32_t value);

		// Returns a RGB Color representation of the integer value, with Alpha = 255
		static Color from_rgb(uint32_t value);
		
		static Color lerp(Color a, Color b, float amount);

		// Mutliplties the Color
		Color operator*(float multiply) const;

		// assignment from int
		Color& operator= (const int rgb);

		static const Color transparent;
		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;
		static const Color yellow;
		static const Color orange;
		static const Color purple;
		static const Color teal;
	};
}
