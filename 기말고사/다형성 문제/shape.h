#pragma once

class Shape {
	static int gid;							// 디폴트 생성될때마다 고유번호를 부여한다

protected:
	int id;

public:
	Shape() : id( ++gid ) { 	}

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };
