#ifdef CHESSPLUSPLUSDLL_EXPORTS
#define CHESSPLUSPLUSDLL_API __declspec(dllexport)
#else
#define CHESSPLUSPLUSDLL_API __declspec(dllimport)
#endif

#pragma warning (disable : 4251 )