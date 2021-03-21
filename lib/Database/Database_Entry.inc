#include <YSI_Coding\y_hooks>

static 
    MySQL:SQL;    // Main Database Connection Handler

/*
 * API
 */

/**
 * <summary> Database handle for connection.</summary>
 * <returns> Database handle.</returns>
 */
stock MySQL:Database_Handle()
{
    return SQL;
}

/*
 * Callbacks
 */

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    return 1;
}

/*
 * Hooks
 */

hook OnGameModeInit()
{
	SQL = mysql_connect_file();
	if(SQL == MYSQL_INVALID_HANDLE)
	{
		print("[SERVER ERROR]: Failed to connect MySQL Database!");
		return 1;
	}
	mysql_log(ERROR | WARNING);
	print("Report: MySQL Connection & Log Mode Established.");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    mysql_close(SQL);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
