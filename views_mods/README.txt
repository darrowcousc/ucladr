TODO: Create Readme based on "Views Datasource" readme, which is copied below.

Views Datasource README
-------------------------------------------------------------------------------

About
-----
Views Datasource is a set of plugins for Views for rendering node content in a
set of shareable, reusable data formats based on XML, JSON, and XHTML. These
formats allow content in a Drupal site to be easily used as data sources for
Semantic Web clients and web mash-ups. Views Datasource plugins output content
from node lists created in Drupal Views as:
  1)XML data documents using schemas like OPML and Atom;
  2)RDF/XML data documents using vocabularies like FOAF, SIOC and DOAP;
  3)JSON data documents in plain JSON or in a format like MIT Simile/Exhibit;
  4)XHTML data documents using microformat like hCard and hCalendar

The project consists of 4 Views style plugins:
  1)views_xml - Output as raw XML, OPML, and Atom;
  2)views_json - Output as simple JSON, Simile/Exhibit JSON and JqGrid;
  3)views_rdf - Output as FOAF, SIOC and DOAP;
  4)views_xhtml - Output as hCard and hCalendar.

In Drupal 7.x, to use these plugins you should:
1) Enable the module containing the format you want to render your views as.
2) In the Views UI set the view style (in Basic Settings) to one of:
   i)  JSON data document (render as Simple JSON or Simile/Exhibit JSON)
   ii) XML data document (render as raw XML, OPML, or Atom)
   iii) RDF data document (render as a FOAF or SIOC or DOAP RDF/XML document)
   iv) XHTML data document (render as hCard or hCalendar XHTML)
3) In the view style options choose the options or vocabulary for your format
   (like raw or the OPML or Atom vocabulary for XML rendering.)
4) Add the fields to your view that contain the information you want to be
   pulled into the format renderer. All formats will output the fields
   recognized as belonging to that format, and certain formats like Atom and
   SIOC require certain fields to be present (see below.)
   The SIOC format requires the fields: node nid, type, title, body, posted date
5) That's it! The rendered view will be visible in the preview and at your
   view's page displaypath. When you create a page display for your view with a unique URL,
   no Drupal markup is emitted from this page, just the data for the particular
   content type with the proper Content-Type HTTP header (like text/xml or
   application/rdf+xml.)

A JSON data document will render the nodes generated by a view as a
serialization of an array of Javascript objects with each object's properties
corresponding to a view field. Simple JSON is just plain-vanilla JSON
serialization usable in most apps while Simile/Exhibit JSON is the serialization
format used by the Exhibit web app - http://simile.mit.edu/exhibit/

An XML data document with render the nodes generated by a view as XML. The raw
XML format creates a root element called 'nodes' and then a 'node' child element
for each node in the view, with each node's child elements corresponding to a
view field. OPML is a very simple XML schema useful for generating simple lists
(like lists of tracks in an music playlist.) Atom is a syndication schema with
similar intents as RSS. The following fields will bviews_rdf will render
the nodes generated by a view as an RDF/XML FOAF document with each
<foaf:Person> element corresponding to a node in the view. To use just have
fields in the view named as their equivalent FOAF properties - for example to
have a <foaf:name> or <foaf:nick> element, have a field named 'name' and 'nick'
in your view. Similarly views_xhtml provides the hCard plugin which will render
each node in the XHTML hCard format - just have fields corresponding to hCard
properties defined in the view. For example to create an <email> element inside
the <div class="hcard"> root element, just have one or more fields in the view
containing the text 'email'.

The FOAF and hCard renderers are most useful with view based on user profiles
where you can create profile fields corresponding to properties defined in the
FOAF (http://xmlns.com/foaf/spec/) or hCard
(http://microformats.org/wiki/hcard-cheatsheet) spec. However any node type
(like those created with nodeprofile or Bio or Advanced Profile or Content
Profile) can be used in the view. It doesn't matter what data table the view
is based on, only what fields are present in the view.

OPTIONS
------
Each style has a range of options you can use to customize the output:

 The following options are common to all plugins:
  1. Field output: Normal or Raw
      This determines if each object in the view is displayed as normally
      rendered by Drupal, or as the raw result object. Raw is useful if
      you don't want any Drupal formatting applied to the view result, for
      example, if you have a field with a date and you just want the timestamp
      value from the database. Note that both a field's label and content are
      rendered as raw so XML element or attribute labels will have the internal
      field name - for example instead of 'Body' a raw field will have the
      label 'node_revisions_body'.
  2. Plaintext output
      Selecting this neans that all HTML markup will be stripped from the
      view result. This is useful, for example, if you are generating an
      XML document from nodes and you just want the plain text content
      of a node without markup tags mixing with the other XML elements.
     (Note that you can also escape XML content using CDATA sections,
     see below.)
  3. Content-Type
      This determine the Content-Type header sent in a page display of
      a view. This header is necessary for most clients consuming data
      from the view. You can use the default Content-Type for the
      particular plugin or choose from alternate types.
  4. Use Views API mode - by default the plugins stop Drupal from
      doing any additional processing when a view is rendered - allowing
      the content to be output without any additional Drupal markup.
      However if you are calling a view programatically then this will
      hlar your code prematurely. The solution (contributed by icylake)
      is to use the Use Views API mode option if you are going to call
      the view from code. This option causes the plugin to not terminate
      Drupal execution.

 The following options are common to the views_xml, and views_xhtml plugins:
  1. Escape row content as CDATA
      This option escapes all content from the result row using the ![CDATA[
      XML directive. This is useful if you want all content markup preserved,
      but kept separate from the other XML tags in the document. You will
      have to instruct your client that the data you are processing is
      in CDATA blocks, and different XML processors may handle these blocks
      differently.
  2. XML document header
      This option lets you specify the XML document header which precedes the
      root XML element. If you specify a header here it will override any
      header generated automatically by the plugin.

 The views_json plugin has the following options:
  1. Root object name
      This specifies the name of the top-level object in the JSON object. The
      default is the name of the view base table (nodes, users, etc.)
  2. JSON data format
      This specifies the format of the JSON output - either simple, plain-
      vanilla JSON, or the JSON format compatible with the Simile/Exhibit
      application.

 The views_xml plugin has the following options:
  1. XML schema:
      This specifies the XML schema the view will render.
      Raw simply renders each view field using the field name as
      a element/attribute label and the field content as the element/attribute
      value.

      OPML renders each field as an attribute-value pair in an <outline>
      element. The OPML schema requires at least one field labelled 'text' - or
      if this is not found it falls back to 'body' or 'node_revisions_body'.
      The following fields are recommended (fallback in brackets):
      type (node_type), created(published, node_created, Post date).

      Atom renderes a view using the Atom syndication schema. You can use this
      format to create an Atom syndication of the content in your view. Atom
      requires the following fields to be present (fields in bracket indicate
      what the plugin will fall back to if it can find the explicitly named
      Atom field):
      id (nid), title(node_title) updated(last_updated, Updated date, changed,
      Last updated/commented, Last comment time)
      The following fields are recommended: content(Body, node_body,
      node_revisions_body), link (nid {a link will be constructed from the
      Drupal path and the nid), summary author(uid).

  2. Root element name:
      Only applies to the Raw XML schema. This specifies the root XML element
      in the document. All other elements will be children of this element.
      The default is the name of the view base table.

  3. Element output:
      Only applies to the Raw XML schema. This specifies whether the view
      fields will be output as nested child elements or attributes. For example
      if Element output is set to Nested then a field labelled 'title' with
      content 'foo' will be output as <title>foo</title> If Element output
      is set to Attributes then this field will be output as title = "foo"
      for each row element. Note that the plugin automatically strips invalid
      XML element and attribute label characters (like spaces), so a field like
      'Post date' will become 'postdate'.

  4. View author:
      This is used by the Atom and OPML plugins to provide the author
      of the Atom or OPML document. It can be a valid Drupal user name,
      a Drupal user uid, or any name otherwise.

 The views_rdf plugin has the following options:
  1. RDF vocabulary:
     This indicates what RDF vocabulary to use in the document: either
     FOAF or SIOC or DOAP . FOAF (Friend of a Friend) is useful for sharing a
     list of  users or people, while SIOC
     (Semantically-Interlinked Online Communities Project) is most useful for
     describing a set of pages, stories, blogs,
     or forum posts with comments from different people. SIOC itself uses
     FOAF to describe the posts and comments from different people. DOAP
     (Description of a Project) is useful for - as the name suggests - projects.
     See these links for more info:
      http://www.foaf-project.org/
      http://sioc-project.org/
      http://trac.usefulinc.com/doap

     The following fields are recognized when using the FOAF vocabulary
     (fallbacks in brackets):
     name, firstname, surname, title, nick, mbox (mail, email), mbox_sha1sum,
     openid, workplacehomepage, homepage, weblog, img, depiction, member,
     phone, jabberID, msnChatID, aimChatID, yahooChatID.

     The following fields are required when using the SIOC vocabulary:
     id (nid), created(node_created, Post date, title, type (node_type),
     changed (node_changed, updated/commented date) last_updated(updated date),
     body(node_body, node_revisions_body), uid (users_uid).

     The following fields are recognized when using the DOAP vocabulary:
     (optional fields in square brackets)
     nid, name, homepage, [license], [shortdesc], [language], [repositories],
     [developers]

 The views_xhtml plugin has the following options:
  1. Microformat
     This specifies the microformat to be rendered: hCard is most useful for a
     list of users or people. hCalendar can be used to describe a list of
     events.
     The following fields are recognized by hCard:
     Address Type, Post office box, Street Address, Extended Address, region,
     Locality. Postal Code, Country name, agent, bday, class, category, email,
     honorific prefix, Given name, Additional name, Family name, Honoric suffix,
     Nickname, Organization name, Organization unit, photo, tel.

     The following fields are recognized by hCalendar:
     class, category, description, summary, dtstart(Event start, event_start)
     dtend(Event end, event_end).


TODO
----
 Proper date handling for each format
 Check for separator in profile fields
 Properly handle grouped multiple values in views_xhtml et. al
 Strict conformance with Atom spec
 Recognize when field rewriting rules are used
 Represent multiple-valued fields using nested child elements
