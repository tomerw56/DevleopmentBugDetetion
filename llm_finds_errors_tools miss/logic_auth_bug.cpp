// logic_auth_bug.cpp
#include <string>

struct User
{
    bool HasPermission(const std::string& perm) const;
};

bool IsAuthorized(const User* user)
{
    if (!user)
        return true;   //Logic: null treated as authorized

    return user->HasPermission("admin");
}
