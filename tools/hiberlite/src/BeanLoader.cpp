#include <hiberlite/hiberlite.h>

namespace hiberlite{

BeanLoader::BeanLoader() : AVisitor<LoadBean>(&actor, LOADING)
{}

} //namespace hiberlite
