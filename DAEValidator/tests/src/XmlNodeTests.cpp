#include "Common.h"
#include "XmlAttribute.h"
#include "XmlDoc.h"
#include "XmlNamespace.h"
#include "XmlNode.h"
#include "XmlNodes.h"

#include "no_warning_string"
#include "no_warning_vector"

using namespace opencollada;
using namespace std;

namespace opencollada_test
{
	TEST_CLASS(XmlNodeTest)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			XmlNode node;
			Assert::IsFalse(node);
		}

		TEST_METHOD(OperatorBool)
		{
			XmlNode null;
			Assert::IsFalse(null);

			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();
			Assert::IsTrue(root);
		}

		TEST_METHOD(OperatorIsEqual)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode null;
			XmlNode root = doc.root();
			
			Assert::IsFalse(root == null);
			Assert::IsTrue(root == root);
			Assert::IsTrue(null == null);
		}

		TEST_METHOD(OperatorIsNotEqual)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode null;
			XmlNode root = doc.root();

			Assert::IsTrue(root != null);
			Assert::IsFalse(root != root);
			Assert::IsFalse(null != null);
		}

		TEST_METHOD(Doc)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();

			const XmlDoc & doc2 = root.doc();
			Assert::IsTrue(doc2);
		}

		TEST_METHOD(Child)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();
			XmlNode asset = root.child("asset");
			Assert::IsTrue(asset);
			XmlNode library_animations = root.child("library_animations");
			Assert::IsTrue(library_animations);
			XmlNode unknown = root.child("unknown");
			Assert::IsFalse(unknown);
		}

		TEST_METHOD(FirstChild)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();
			
			XmlNode first_child = root.firstChild();
			Assert::AreEqual("asset", first_child.name().c_str());
			
			first_child = first_child.firstChild();
			Assert::AreEqual("created", first_child.name().c_str());
			
			first_child = first_child.firstChild();
			Assert::IsFalse(first_child);
		}

		TEST_METHOD(Text)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();
			Assert::AreEqual("\n\t", root.text().c_str());

			XmlNode created = root.child("asset").child("created");
			Assert::AreEqual("2017-03-08T13:35:39", created.text().c_str());
		}

		TEST_METHOD(Name)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();
			Assert::AreEqual("COLLADA", root.name().c_str());

			XmlNode asset = root.child("asset");
			Assert::AreEqual("asset", asset.name().c_str());
		}

		TEST_METHOD(Attribute)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();
			XmlNode channel = root.child("library_animations").child("animation").child("channel");
			XmlAttribute source = channel.attribute("source");
			Assert::IsTrue(source);
			XmlAttribute target = channel.attribute("target");
			Assert::IsTrue(target);
			XmlAttribute unknown = channel.attribute("unknown");
			Assert::IsFalse(unknown);
		}

		TEST_METHOD(Ns)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();
			Assert::IsTrue(root.ns());
			Assert::AreEqual("http://www.collada.org/2005/11/COLLADASchema", root.ns().href().c_str());

			const XmlNodeSet & rigid_bodies = root.selectNodes("//collada:rigid_body");
			XmlNode rigid_body = rigid_bodies[0];
			XmlNode px_rigid_body = rigid_body.child("extra").child("technique").child("px_rigid_body");
			Assert::IsTrue(px_rigid_body.ns());
			Assert::AreEqual("http://www.collada.org/2016/08/COLLADAPhysX3Schema", px_rigid_body.ns().href().c_str());
		}

		TEST_METHOD(SelectNodes)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();

			const auto & COLLADAs = root.selectNodes("//collada:COLLADA");
			Assert::AreEqual(static_cast<size_t>(1), COLLADAs.size());

			const auto & sources = root.selectNodes("//collada:source");
			Assert::AreEqual(static_cast<size_t>(6), sources.size());

			const auto & unknowns = root.selectNodes("//unknown");
			Assert::AreEqual(static_cast<size_t>(0), unknowns.size());
		}

		TEST_METHOD(Children)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();

			auto assets = root.children("asset");
			size_t count = 0;
			for (auto asset : assets)
				++count;
			Assert::AreEqual(static_cast<size_t>(1), count);

			auto sources = root.child("library_animations").child("animation").children("source");
			count = 0;
			for (auto source : sources)
				++count;
			Assert::AreEqual(static_cast<size_t>(2), count);

			auto unknowns = root.children("unknown");
			Assert::IsFalse(unknowns.begin() != unknowns.end());
		}

		TEST_METHOD(Next)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode asset = doc.root().child("asset");

			XmlNode next = asset.next("unknown");
			Assert::IsFalse(next);

			next = asset.next("library_animations");
			Assert::IsTrue(next);

			next = next.next("library_visual_scenes");
			Assert::IsTrue(next);
		}

		TEST_METHOD(Line)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));

			XmlNode root = doc.root();
			Assert::AreEqual(static_cast<size_t>(2), root.line());

			XmlNode asset = root.child("asset");
			Assert::AreEqual(static_cast<size_t>(3), asset.line());

			XmlNode library_visual_scenes = root.child("library_visual_scenes");
			Assert::AreEqual(static_cast<size_t>(164), library_visual_scenes.line());
		}

		TEST_METHOD(ForEachAttribute)
		{
			XmlDoc doc;
			doc.readFile(data_path("xml/file.dae"));
			XmlNode root = doc.root();
			XmlNode channel = root.child("library_animations").child("animation").child("channel");
			vector<string> attribute_names;
			channel.for_each_attribute([&](const XmlAttribute & attr) {
				attribute_names.push_back(attr.name());
			});
			vector<string> expected{ "source", "target" };
			Assert::IsTrue(expected == attribute_names);
		}

		TEST_METHOD(StringUnsignedCharOperatorIsEqual)
		{
			string empty_s = "";
			string s = "string";
			unsigned char* empty_c = BAD_CAST "";
			unsigned char* c = BAD_CAST "string";

			Assert::IsTrue(empty_s == empty_c);
			Assert::IsTrue(s == c);
			Assert::IsFalse(empty_s == c);
			Assert::IsFalse(s == empty_c);
		}
	};
}