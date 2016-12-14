
#include "Dae.h"
#include "COLLADASWConstants.h"
#include <string>
#include <set>

using namespace COLLADASW;
using namespace std;

namespace opencollada
{
	const string xpath_all = "//collada:";
	const string xpath_or_all = "|//collada";

	Dae::Dae(Dae && other)
		: XmlDoc(move(other))
	{}

	void Dae::readFile(const string & path)
	{
		mUri.set(COLLADABU::URI::nativePathToUri(path));

		Super::readFile(path);

		if (!*this)
			return;

		// List referenced DAEs

		// InstanceWithExtra and other <instance_*> with "url" attribute
		auto instances = root().selectNodes(
			xpath_all + CSWC::CSW_ELEMENT_INSTANCE_ANIMATION +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_CAMERA +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_CONTROLLER +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_EFFECT +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_FORCE_FIELD +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_GEOMETRY +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_LIGHT +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_NODE +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MATERIAL +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_SCENE +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_VISUAL_SCENE
			);
		for (auto instance : instances)
		{
			if (auto url = instance.attribute(CSWC::CSW_ATTRIBUTE_URL))
			{
				onAnyDAEURI(url.value());
			}
		}

		// <accessor>
		auto accessors = root().selectNodes(xpath_all + CSWC::CSW_ELEMENT_ACCESSOR);
		for (auto accessor : accessors)
		{
			if (auto source = accessor.attribute(CSWC::CSW_ATTRIBUTE_SOURCE))
			{
				onAnyDAEURI(source.value());
			}
		}

		// <skin>/<morph>
		auto elementsWithSource = root().selectNodes(
			xpath_all + CSWC::CSW_ELEMENT_SKIN +
			xpath_or_all + CSWC::CSW_ELEMENT_MORPH
			);
		for (auto element : elementsWithSource)
		{
			if (auto source = element.attribute(CSWC::CSW_ATTRIBUTE_SOURCE))
			{
				onAnyDAEURI(source.value());
			}
		}

		// <render>
		auto renders = root().selectNodes(xpath_all + CSWC::CSW_ELEMENT_RENDER);
		for (auto render : renders)
		{
			if (auto camera_node = render.attribute("camera_node"))
			{
				onAnyDAEURI(camera_node.value());
			}
		}

		// <skeleton>
		auto skeletons = root().selectNodes(xpath_all + CSWC::CSW_ELEMENT_SKELETON);
		for (auto skeleton : skeletons)
		{
			onAnyDAEURI(skeleton.text());
		}

		// <instance_material>/<instance_rigid_body>
		auto elementsWithTarget = root().selectNodes(
			xpath_all + CSWC::CSW_ELEMENT_INSTANCE_MATERIAL +
			xpath_or_all + CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY
			);
		for (auto element : elementsWithTarget)
		{
			if (auto target = element.attribute(CSWC::CSW_ATTRIBUTE_TARGET))
			{
				onAnyDAEURI(target.value());
			}
		}

		// <instance_physics_model>
		auto instance_physics_models = root().selectNodes(xpath_all + CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL);
		for (auto instance_physics_model : instance_physics_models)
		{
			if (auto parent = instance_physics_model.attribute(CSWC::CSW_ATTRIBUTE_PARENT))
			{
				onAnyDAEURI(parent.value());
			}
		}

		// <convex_mesh>
		auto convex_meshes = root().selectNodes(xpath_all + CSWC::CSW_ELEMENT_CONVEX_MESH);
		for (auto convex_mesh : convex_meshes)
		{
			if (auto convex_hull_of = convex_mesh.attribute(CSWC::CSW_ATTRIBUTE_CONVEX_HULL_OF))
			{
				onAnyDAEURI(convex_hull_of.value());
			}
		}

		// <ref_attachment>/<attachment>
		auto attachments = root().selectNodes(
			xpath_all + CSWC::CSW_ELEMENT_ATTACHMENT +
			xpath_or_all + CSWC::CSW_ELEMENT_REF_ATTACHMENT
			);
		for (auto attachment : attachments)
		{
			if (auto rigid_body = attachment.attribute(CSWC::CSW_ATTRIBUTE_RIGID_BODY))
			{
				onAnyDAEURI(rigid_body.value());
			}
		}

		// Load found DAE references
		for (const auto & uri : mExternalDAEURIs)
		{
			Dae dae;
			dae.readExternalFile(uri.toNativePath());
			if (dae)
			{
				mExternalDAEs.push_back(move(dae));
			}
		}
	}

	const COLLADABU::URI & Dae::getURI() const
	{
		return mUri;
	}

	void Dae::readExternalFile(const string & url)
	{
		// Simple load file but not the references
		Super::readFile(url);
	}

	void Dae::onAnyDAEURI(const string & uri)
	{
		COLLADABU::URI absoluteUri(mUri, uri);
		if (!absoluteUri.getPathFile().empty())
		{
			COLLADABU::URI absoluteUriNoFragment(absoluteUri, true);
			if (absoluteUriNoFragment != mUri)
			{
				mExternalDAEURIs.insert(absoluteUriNoFragment);
			}
		}
	}
}