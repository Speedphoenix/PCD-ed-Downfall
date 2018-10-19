#include "Teleporter.h"

#include "CreateAnimator.h"

Teleporter::Teleporter(Player *_owner, double _x, double _y)
	:Moveable(teleporterSpeed, _x, _y, teleporterWidth, teleporterHeight),
	m_collider(this, m_transform), m_owner(_owner)
{
	CreateAnimator::telepAnimator(m_animator);
}

Teleporter::~Teleporter()
{

}
