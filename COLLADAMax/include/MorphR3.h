/*
Copyright (C) 2005-2007 Feeling Software Inc.
Portions of the code are:
Copyright (C) 2005-2007 Sony Computer Entertainment America

MIT License: http://www.opensource.org/licenses/mit-license.php
*/

/*
Based off the 3dsMax COLLADASW Tools
Copyright (C) 2005-2007 Feeling Software Inc.
Copyright (C) 2005-2006 Autodesk Media & Entertainment.
*/

/*
Morpher Modifier Importer Class
*/

#ifndef _MORPHER_INTERFACE_H_
#define _MORPHER_INTERFACE_H_

#include <vector>

#define MORPHER_CLASS_ID		Class_ID(0x17bb6854, 0xa5cba2a3)
#define MORPHER_CHANNEL_COUNT	100
#define MORPHER_MAX_TARGET		25
#define MORPHER_FILE_VERSION	0x0195

#define DLLImport __declspec(dllimport)

class MorphR3;

/**
* ST - 20 Sept 2006
* FIX - Morph Export Bug:
* Changes in the way the Vectors are compiled are creating differences
* between the class defined here and the object created by Max.  These
* differences cause chanBank to return size() == 0 every time.
* To Fix: Defined custom *vector* obj to match vector object Max uses,
* encapsulates all the functionality we need from the vector obj.
**/

template<class T>
class stdVector
{
private:
	// Ignore first 4 bytes. What were they used for anyway?
	DWORD pad;
	T *_First;	// Typical vector member
	T *_Last;	// Typical vector member
	T *_End;	// Typical vector member

public:
	size_t size() {
		return size_t(_Last - _First);
	}
	T& operator[](size_t i)
	{
		return *(_First + i);
	}
};
/** ST - done **/

class morphChannel
{
public:
	MorphR3 *mp;

	// Unused
	float mCurvature;

	// Number of points
	int mNumPoints;

	int iTargetListSelection;

	// Actual morphable points
	stdVector<Point3> mPoints;
	stdVector<Point3> mDeltas;
	stdVector<double> mWeights;

	// Unused
	stdVector<int> mTargetCache;
	BitArray mSel;
	INode* mConnection;
	TSTR mName;
	int mNumProgressiveTargs;
	float mTargetPercent;
	BOOL mActive, mModded, mUseLimit, mUseSel;
	float mSpinmin,mSpinmax;
	BOOL mInvalid;
	BOOL mActiveOverride;

	// For the animated weight, the parameter block is contained in the morphChannel.
	// It contains only one parameters for the weight.
	static const unsigned int cblock_weight_index = 0;
	IParamBlock* cblock;

	// Allocate the necessary buffer memory for a given number of points
	// Always let sizeA == sizeB. Although, sizeB is seems unused.
	DLLImport void AllocBuffers(int sizeA, int sizeB);

	// Initialize a channel using a scene node
	DLLImport void buildFromNode(INode *node , BOOL resetTime=TRUE , TimeValue t=0, BOOL picked = FALSE);
};

class morphCache
{
public:
	BOOL valid;
	Point3* points;
	double* weights;
	BitArray selection;
	int count;

	DLLImport void MakeCache(Object *obj);
	DLLImport void NukeCache();
	DLLImport BOOL AreWeCached();
};

class MorphR3 : public Modifier, TimeChangeCallback
{
private:
	MorphR3() {}
	~MorphR3() {}

public:
	// Please check against MORPHER_FILE_VERSION before using this interface
	float mFileVersion;


	// Pointer to the morph channels
	//std::vector<morphChannel> chanBank;
	stdVector<morphChannel> chanBank;

	// Unused variable. Kept their name for forward-compatibility
	void* morphmaterial;
	int chanSel;
	int	chanNum;
	void* chanSpins[10];
	void* glSpinmin, * glSpinmax;
	void* cSpinmin,* cSpinmax,* cCurvature,* cTargetPercent;
	void* pblock;
	void* hwGlobalParams,* hwChannelList,* hwChannelParams,* hwAdvanced,* hwLegend;
	void* newname;

	// Morph Cache
	morphCache cache;

	// Unused variable. Kept their name for forward-compatibility
	BOOL tccI;
	char trimD[50];
	BOOL recordModifications;
	int recordTarget;
	Tab<int> markerIndex;
	NameTab markerName;
	int markerSel;
	int cOp;
	int srcIdx;
	bool hackUI;

	// Fully updates the channel UI
	DLLImport void Update_channelFULL();
	DLLImport void Update_channelParams();
};

#endif // _MORPHER_INTERFACE_H_
