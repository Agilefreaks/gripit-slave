#pragma once

template <typename Base, typename T> inline bool instanceof(const T *instance)
{
	return dynamic_cast<const Base*>(instance) != nullptr;
}