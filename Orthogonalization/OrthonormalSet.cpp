#include <iostream>

#include "OrthonormalSet.h"


OrthonormalSet::OrthonormalSet(const Set& vectors)
{
	orthogonalize(vectors);
}

void OrthonormalSet::orthogonalize(const Set& vectors)
{
	m_orthonormalSet.push_back(vectors[0]);
	m_orthonormalNormalizedSet.push_back(vectors[0].normalize());

	for (auto from_iter = vectors.cbegin() + 1; from_iter != vectors.cend(); from_iter++)
	{
		Vec3D orthogonalizedVec = *from_iter;

		for (const auto& onto_orthonormalVec : m_orthonormalSet)
		{
			const Vec3D projectedVec = project(*from_iter, onto_orthonormalVec);

			orthogonalizedVec = orthogonalizedVec - projectedVec;
		}

		m_orthonormalSet.push_back(orthogonalizedVec);
		m_orthonormalNormalizedSet.push_back(orthogonalizedVec.normalize());
	}
}

Vec3D OrthonormalSet::project(const Vec3D& from, const Vec3D& onto) const
{
	const double dot = onto.dot(from);
	const double length = onto.length();

	const Vec3D projectedVec = (dot / (length * length)) * onto;

	return projectedVec;
}

void OrthonormalSet::print() const
{
	for (const auto& item : m_orthonormalNormalizedSet)
	{
		std::cout << item.x << ":" << item.y << ":" << item.z << std::endl;
	}
}