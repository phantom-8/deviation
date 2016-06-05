/*
 This project is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Deviation is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Deviation.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "common.h"
#include "pages.h"

#include "protocol/interface.h"
extern void * (* const PROTO_Cmds)();
static u8 bind_shortcut_active = 0;

void PAGE_BindInit(int page)
{
    (void)page;
    PAGE_RemoveAllObjects();
    bind_shortcut_active = 1;
    PROTO_Cmds(PROTOCMD_BIND);
}


/* Restore to main page if Bind activated via shortcut */
void PAGE_BindCleanup()
{
    if (bind_shortcut_active) {
	PAGE_Pop();
        bind_shortcut_active = 0;
    }
}
