/* Copyright (c) 2016-2025 Li Jin <dragon-fly@qq.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

#define NS_DORA_PLATFORMER_BEGIN namespace Dora::Platformer {
#define NS_DORA_PLATFORMER_END }

#define NS_DECISION_BEGIN namespace Decision {
#define NS_DECISION_END }

#define NS_BEHAVIOR_BEGIN namespace Behavior {
#define NS_BEHAVIOR_END }

NS_DORA_PLATFORMER_BEGIN

enum struct Relation {
	Unknown = 0,
	Friend = 1 << 0,
	Neutral = 1 << 1,
	Enemy = 1 << 2,
	Any = Friend | Neutral | Enemy
};

/*
Target Allow
	Relation
		Unkown 0
		Friend 1 << 0
		Neutral 1 << 1
		Enemy 1 << 2
	Group
		SharedData.getTerrainGroup() 1 << 3
*/
class TargetAllow {
public:
	TargetAllow(uint32_t flag = 0);
	bool operator==(const TargetAllow& other) const;
	bool operator!=(const TargetAllow& other) const;
	void setTerrainAllowed(bool var);
	bool isTerrainAllowed() const;
	void allow(Relation relation, bool allow);
	bool isAllow(Relation relation);
	uint32_t toValue() const;

protected:
	uint32_t _flag;
};

NS_DORA_PLATFORMER_END
