#pragma once

class Shape {
	static int gid;							// ����Ʈ �����ɶ����� ������ȣ�� �ο��Ѵ�

protected:
	int id;

public:
	Shape() : id( ++gid ) { 	}

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };
