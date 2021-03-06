#pragma once
#include "EuroScopePlugIn.h"
#include "SituPlugin.h"
#include <chrono>
#include <time.h>
#include <ctime>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "pch.h"

using namespace EuroScopePlugIn;
using namespace std;

struct ACData {
    bool hasCTP;
    string slotTime;
    string CID = "";
    string TAG_ITEM_NAT_STATUS = "";
    string TAG_ITEM_NAT_NAT = "";
    string TAG_ITEM_NAT_FIX = "";
    string TAG_ITEM_NAT_LEVEL = "";
    string TAG_ITEM_NAT_MACH = "";
    string TAG_ITEM_NAT_ESTTIME = "";
    string TAG_ITEM_NAT_CLR = "";
    string TAG_ITEM_NAT_EXTRA = "";
};

class CSiTRadar :
    public EuroScopePlugIn::CRadarScreen

{
public:
    static bool canAmend;
    static int refreshStatus;
    static int amendStatus;
    static POINT menu;
    static int tagLocation;

    CSiTRadar(void);
    virtual ~CSiTRadar(void);

    static map<string, ACData> mAcData; 
    static map<int, string> slotTime;
    static string eventCode;

    inline virtual void OnFlightPlanDisconnect(CFlightPlan FlightPlan);
    static void RegisterButton(RECT rect) {};

    void OnRefresh(HDC hdc, int phase);

    void CSiTRadar::OnClickScreenObject(int ObjectType,
        const char* sObjectId,
        POINT Pt,
        RECT Area,
        int Button);

    inline  virtual void    OnFunctionCall(int FunctionId,
        const char* sItemString,
        POINT Pt,
        RECT Area);

    inline virtual void OnAsrContentToBeClosed(void) {

        delete this;
    };

    void CSiTRadar::OnMoveScreenObject(int ObjectType,
        const char* sObjectId,
        POINT Pt,
        RECT Area,
        bool Released);

protected:
    void ButtonToScreen(CSiTRadar* radscr, RECT rect, string btext, int itemtype);

    const int BUTTON_MENU_REFRESH = 1200;
    const int BUTTON_MENU_AMENDFP = 1201;
    const int BUTTON_MENU_SETTINGS = 1202;

    const int FUNCTION_SET_URL = 301;

    BOOL autoRefresh = FALSE;
    clock_t time; 
    clock_t oldTime;
};
