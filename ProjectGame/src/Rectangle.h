//
//  Rectangle.h
//  SharpEngine
//
//  Created by ccf on 16/9/21.
//  Copyright © 2016年 ccf. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include "PlatformMacros.h"
#include "Vec2.h"
#include "Vec3.h"

NS_SP_BEGIN

class Rectangle
{
public:
	Rectangle();
	Rectangle(const Vec2& position, const Vec2& size);
	Rectangle(float x, float y, float width, float height);

	bool intersects(const Rectangle& other) const;
	bool contains(const Vec2& point) const;
	bool contains(const Vec3& point) const;

	Vec2 center() const;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool operator<(const Rectangle& other) const;
	bool operator>(const Rectangle& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const Rectangle& Rectangle);
public:
	union
	{
		Vec2 position;
		struct
		{
			float x;
			float y;
		};
	};
	union
	{
		Vec2 size;
		struct
		{
			float width;
			float height;
		};
	};
};

NS_SP_END

#endif /* Rectangle_h */