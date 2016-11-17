
#include "Dae.h"
#include "Strings.h"
#include <string>
#include <set>

// TODO remove
#include <iostream>

using namespace std;

namespace opencollada
{
	const string xpath_all = "//collada:";
	const string xpath_or_all = "|//collada:";

	Dae::Dae(Dae && other)
		: XmlDoc(move(other))
	{}

	void Dae::readFile(const string & path)
	{
		mUri = Uri::FromNativePath(path);

		Super::readFile(path);

		if (!*this)
			return;

		// List referenced DAEs

		// InstanceWithExtra and other <instance_*> with "url" attribute
		auto instances = root().selectNodes(
			xpath_all + Strings::instance_animation +
			xpath_or_all + Strings::instance_camera +
			xpath_or_all + Strings::instance_controller +
			xpath_or_all + Strings::instance_effect +
			xpath_or_all + Strings::instance_force_field +
			xpath_or_all + Strings::instance_geometry +
			xpath_or_all + Strings::instance_light +
			xpath_or_all + Strings::instance_node +
			xpath_or_all + Strings::instance_physics_material +
			xpath_or_all + Strings::instance_physics_model +
			xpath_or_all + Strings::instance_physics_scene +
			xpath_or_all + Strings::instance_visual_scene
			);
		for (auto instance : instances)
		{
			if (auto url = instance.attribute(Strings::url))
			{
				onAnyDAEURI(url.value());
			}
		}

		// <accessor>
		auto accessors = root().selectNodes(xpath_all + Strings::accessor);
		for (auto accessor : accessors)
		{
			if (auto source = accessor.attribute(Strings::source))
			{
				onAnyDAEURI(source.value());
			}
		}

		// <skin>/<morph>
		auto elementsWithSource = root().selectNodes(
			xpath_all + Strings::skin +
			xpath_or_all + Strings::morph
			);
		for (auto element : elementsWithSource)
		{
			if (auto source = element.attribute(Strings::source))
			{
				onAnyDAEURI(source.value());
			}
		}

		// <render>
		auto renders = root().selectNodes(xpath_all + Strings::render);
		for (auto render : renders)
		{
			if (auto camera_node = render.attribute("camera_node"))
			{
				onAnyDAEURI(camera_node.value());
			}
		}

		// <skeleton>
		auto skeletons = root().selectNodes(xpath_all + Strings::skeleton);
		for (auto skeleton : skeletons)
		{
			onAnyDAEURI(skeleton.text());
		}

		// <instance_material>/<instance_rigid_body>
		auto elementsWithTarget = root().selectNodes(
			xpath_all + Strings::instance_material +
			xpath_or_all + Strings::instance_rigid_body
			);
		for (auto element : elementsWithTarget)
		{
			if (auto target = element.attribute(Strings::target))
			{
				onAnyDAEURI(target.value());
			}
		}

		// <instance_physics_model>
		auto instance_physics_models = root().selectNodes(xpath_all + Strings::instance_physics_model);
		for (auto instance_physics_model : instance_physics_models)
		{
			if (auto parent = instance_physics_model.attribute(Strings::parent))
			{
				onAnyDAEURI(parent.value());
			}
		}

		// <convex_mesh>
		auto convex_meshes = root().selectNodes(xpath_all + Strings::convex_mesh);
		for (auto convex_mesh : convex_meshes)
		{
			if (auto convex_hull_of = convex_mesh.attribute(Strings::convex_hull_of))
			{
				onAnyDAEURI(convex_hull_of.value());
			}
		}

		// <ref_attachment>/<attachment>
		auto attachments = root().selectNodes(
			xpath_all + Strings::attachment +
			xpath_or_all + Strings::ref_attachment
			);
		for (auto attachment : attachments)
		{
			if (auto rigid_body = attachment.attribute(Strings::rigid_body))
			{
				onAnyDAEURI(rigid_body.value());
			}
		}

		// Load found DAE references
		for (const auto & uri : mExternalDAEURIs)
		{
			Dae dae;
			dae.readExternalFile(uri.nativePath());
			if (dae)
			{
				mExternalDAEs.push_back(move(dae));
			}
		}
	}

	const Uri & Dae::getURI() const
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
		Uri absoluteUri(mUri, uri);
		if (!absoluteUri.pathFile().empty())
		{
			Uri absoluteUriNoFragment(absoluteUri);
			absoluteUriNoFragment.setFragment(string());
			if (absoluteUriNoFragment != mUri)
			{
				mExternalDAEURIs.insert(absoluteUriNoFragment);
			}
		}
	}
}