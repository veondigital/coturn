#include "ns_turn_statistics.h"
#include "ns_turn_utils.h"

struct turn_statistics {
    int active_sessions;
    int total_sessions;
};

struct turn_statistics g_stat;

void stat_clean(void)
{
    // to do http://stackoverflow.com/questions/25647710/atomic-get-load-and-set-store-with-older-gcc-sync-builtins
    __sync_synchronize();
    g_stat.active_sessions = 0;
    g_stat.total_sessions = 0;
    __sync_synchronize();
}


void stat_new_client_connection(void)
{
    __sync_fetch_and_add( &(g_stat.active_sessions), 1 );
    __sync_fetch_and_add( &(g_stat.total_sessions), 1 );
}

void stat_delete_client_connection(void)
{
    __sync_sub_and_fetch( &(g_stat.active_sessions), 1 );
}

void stat_dump(void)
{
    TURN_LOG_FUNC(TURN_LOG_LEVEL_INFO, "*** STATISTICS: active calls %d \n", g_stat.active_sessions);
    TURN_LOG_FUNC(TURN_LOG_LEVEL_INFO, "*** STATISTICS: total calls  %d \n",  g_stat.total_sessions);
}
